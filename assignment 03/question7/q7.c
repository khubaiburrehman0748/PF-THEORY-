#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_RESOLUTION_LENGTH 20
#define MAX_PLAYBACK_HISTORY_LENGTH 100
#define MAX_ENCODING_FORMAT_LENGTH 20

struct ContentMetadata {
    char title[MAX_TITLE_LENGTH];
    float rating;
    int runtime; 
    char encodingFormat[MAX_ENCODING_FORMAT_LENGTH];
};

struct DevicePreferences {
    char resolution[MAX_RESOLUTION_LENGTH];
    char playbackHistory[MAX_PLAYBACK_HISTORY_LENGTH];
    float bandwidthUsage; 
};

void inputEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    printf("\nInitializing engagement scores (default: 0.0)...\n");
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            engagementMatrix[i][j] = 0.0; 
        }
    }
}


void inputDevicePreferences(struct DevicePreferences ***deviceMatrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        deviceMatrix[i] = (struct DevicePreferences **)malloc(numDevices * sizeof(struct DevicePreferences *));
        for (int j = 0; j < numDevices; j++) {
            deviceMatrix[i][j] = (struct DevicePreferences *)malloc(sizeof(struct DevicePreferences));
            printf("\nEnter resolution preference for user %d, device %d: ", i + 1, j + 1);
            scanf(" %[^\n]%*c", deviceMatrix[i][j]->resolution);
            printf("Enter playback history for user %d, device %d: ", i + 1, j + 1);
            scanf(" %[^\n]%*c", deviceMatrix[i][j]->playbackHistory);
            printf("Enter bandwidth usage for user %d, device %d (in Mbps): ", i + 1, j + 1);
            scanf("%f", &deviceMatrix[i][j]->bandwidthUsage);
        }
    }
}

void inputContentMetadata(struct ContentMetadata ***contentMatrix, int numCategories, int numContents) {
    for (int i = 0; i < numCategories; i++) {
        contentMatrix[i] = (struct ContentMetadata **)malloc(numContents * sizeof(struct ContentMetadata *));
        for (int j = 0; j < numContents; j++) {
            contentMatrix[i][j] = (struct ContentMetadata *)malloc(sizeof(struct ContentMetadata));
            printf("\nEnter title for Category %d, Content %d: ", i + 1, j + 1);
            scanf(" %[^\n]%*c", contentMatrix[i][j]->title);
            printf("Enter rating for Category %d, Content %d: ", i + 1, j + 1);
            scanf("%f", &contentMatrix[i][j]->rating);
            printf("Enter runtime for Category %d, Content %d (in minutes): ", i + 1, j + 1);
            scanf("%d", &contentMatrix[i][j]->runtime);
            printf("Enter encoding format for Category %d, Content %d: ", i + 1, j + 1);
            scanf(" %[^\n]%*c", contentMatrix[i][j]->encodingFormat);
        }
    }
}


void displayEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    printf("\n--- Engagement Matrix ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.1f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayDevicePreferences(struct DevicePreferences ***deviceMatrix, int numUsers, int numDevices) {
    printf("\n--- Device Preferences ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("  Device %d: Resolution=%s, Playback History=%s, Bandwidth=%.2f Mbps\n",
                   j + 1, deviceMatrix[i][j]->resolution,
                   deviceMatrix[i][j]->playbackHistory, deviceMatrix[i][j]->bandwidthUsage);
        }
    }
}

void displayContentMetadata(struct ContentMetadata ***contentMatrix, int numCategories, int numContents) {
    printf("\n--- Content Metadata ---\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < numContents; j++) {
            printf("  %s (Rating: %.1f, Runtime: %d min, Format: %s)\n",
                   contentMatrix[i][j]->title, contentMatrix[i][j]->rating,
                   contentMatrix[i][j]->runtime, contentMatrix[i][j]->encodingFormat);
        }
    }
}

int main() {
    int numUsers, numCategories, numDevices, numContents;

    printf("Enter the number of users: ");
    scanf("%d", &numUsers);
    printf("Enter the number of categories: ");
    scanf("%d", &numCategories);
    printf("Enter the number of devices per user: ");
    scanf("%d", &numDevices);
    printf("Enter the number of content items per category: ");
    scanf("%d", &numContents);

    double **engagementMatrix = (double **)malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++) {
        engagementMatrix[i] = (double *)malloc(numCategories * sizeof(double));
    }

    struct DevicePreferences ***deviceMatrix = (struct DevicePreferences ***)malloc(numUsers * sizeof(struct DevicePreferences **));

    struct ContentMetadata ***contentMatrix = (struct ContentMetadata ***)malloc(numCategories * sizeof(struct ContentMetadata **));

  
    inputEngagementMatrix(engagementMatrix, numUsers, numCategories);
    inputDevicePreferences(deviceMatrix, numUsers, numDevices);
    inputContentMetadata(contentMatrix, numCategories, numContents);

    
    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);
    displayDevicePreferences(deviceMatrix, numUsers, numDevices);
    displayContentMetadata(contentMatrix, numCategories, numContents);

    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
        free(engagementMatrix[i]);
    }
    free(deviceMatrix);
    free(engagementMatrix);

    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContents; j++) {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}
