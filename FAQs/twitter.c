#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 1000
#define MAX_TWEETS 100000
#define FEED_SIZE 10

typedef struct {
    int tweetId;
    int userId;
    int time;
} Tweet;

typedef struct {
    int followerId;
    int followeeId;
} Follow;

typedef struct {
    Tweet tweets[MAX_TWEETS];
    int tweetCount;
    Follow follows[MAX_TWEETS];
    int followCount;
    int timestamp;
} Twitter;

// Initialize Twitter
void twitterInit(Twitter *obj) {
    obj->tweetCount = 0;
    obj->followCount = 0;
    obj->timestamp = 0;
}

// Post a tweet
void postTweet(Twitter *obj, int userId, int tweetId) {
    if (obj->tweetCount >= MAX_TWEETS)
        return;

    obj->tweets[obj->tweetCount].tweetId = tweetId;
    obj->tweets[obj->tweetCount].userId = userId;
    obj->tweets[obj->tweetCount].time = ++obj->timestamp;

    obj->tweetCount++;
}

// Check whether follower follows followee
int isFollowing(Twitter *obj, int followerId, int followeeId) {
    if (followerId == followeeId)
        return 1;

    for (int i = 0; i < obj->followCount; i++) {
        if (obj->follows[i].followerId == followerId &&
            obj->follows[i].followeeId == followeeId)
            return 1;
    }

    return 0;
}

// Follow a user
void follow(Twitter *obj, int followerId, int followeeId) {
    if (isFollowing(obj, followerId, followeeId))
        return;

    if (obj->followCount >= MAX_TWEETS)
        return;

    obj->follows[obj->followCount].followerId = followerId;
    obj->follows[obj->followCount].followeeId = followeeId;

    obj->followCount++;
}

// Unfollow a user
void unfollow(Twitter *obj, int followerId, int followeeId) {
    for (int i = 0; i < obj->followCount; i++) {
        if (obj->follows[i].followerId == followerId &&
            obj->follows[i].followeeId == followeeId) {

            obj->follows[i] = obj->follows[obj->followCount - 1];
            obj->followCount--;
            return;
        }
    }
}

// Retrieve the 10 most recent tweets
int* getNewsFeed(Twitter *obj, int userId, int *feedCount) {
    int *feed = malloc(FEED_SIZE * sizeof(int));
    *feedCount = 0;

    // Scan tweets from newest to oldest
    for (int i = obj->tweetCount - 1; i >= 0; i--) {
        int author = obj->tweets[i].userId;

        if (author == userId || isFollowing(obj, userId, author)) {
            feed[(*feedCount)++] = obj->tweets[i].tweetId;

            if (*feedCount == FEED_SIZE)
                break;
        }
    }

    return feed;
}

int main() {
    Twitter twitter;
    twitterInit(&twitter);

    postTweet(&twitter, 1, 101);
    postTweet(&twitter, 2, 102);

    follow(&twitter, 1, 2);

    int count;
    int *feed = getNewsFeed(&twitter, 1, &count);

    printf("User 1 News Feed: ");
    for (int i = 0; i < count; i++)
        printf("%d ", feed[i]);

    printf("\n");
    free(feed);

    unfollow(&twitter, 1, 2);

    feed = getNewsFeed(&twitter, 1, &count);

    printf("After unfollowing User 2: ");
    for (int i = 0; i < count; i++)
        printf("%d ", feed[i]);

    printf("\n");
    free(feed);

    return 0;
}