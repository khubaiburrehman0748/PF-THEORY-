#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    float temperature;
    float rainfall;
    float windPatterns;
};

struct Crop {
    char cropType[20];
    int growthStage;
    float expectedYield;
    struct Weather weather;
};

struct Equipment {
    char equipmentName[20];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[50];
};

struct Sensor {
    char nutrientData[50];
    float pHLevel;
    char pestActivity[50];
};

struct Field {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    struct Crop *crops;
    int numCrops;
    struct Equipment *equipments;
    int numEquipments;
    struct Sensor *sensors;
    int numSensors;
};

struct RegionalHub {
    struct Field *fields;
    int numFields;
    float yieldPrediction;
    char resourceDistribution[100];
    char emergencyResponsePlan[100];
};

// Function to input weather data
void inputWeather(struct Weather *weather) {
    printf("Enter temperature: ");
    scanf("%f", &weather->temperature);
    printf("Enter rainfall: ");
    scanf("%f", &weather->rainfall);
    printf("Enter wind patterns: ");
    scanf("%f", &weather->windPatterns);
}

// Function to input crop data
void inputCrop(struct Crop *crop) {
    printf("Enter crop type: ");
    scanf("%19s", crop->cropType);
    printf("Enter growth stage: ");
    scanf("%d", &crop->growthStage);
    printf("Enter expected yield: ");
    scanf("%f", &crop->expectedYield);
    inputWeather(&crop->weather);
}

// Function to input equipment data
void inputEquipment(struct Equipment *equipment) {
    printf("Enter equipment name: ");
    scanf("%19s", equipment->equipmentName);
    printf("Enter operational status (1 for active, 0 for inactive): ");
    scanf("%d", &equipment->operationalStatus);
    printf("Enter fuel level: ");
    scanf("%f", &equipment->fuelLevel);
    printf("Enter activity schedule: ");
    scanf("%49s", equipment->activitySchedule);
}

// Function to input sensor data
void inputSensor(struct Sensor *sensor) {
    printf("Enter nutrient data: ");
    scanf("%49s", sensor->nutrientData);
    printf("Enter pH level: ");
    scanf("%f", &sensor->pHLevel);
    printf("Enter pest activity: ");
    scanf("%49s", sensor->pestActivity);
}

// Function to input field data
void inputField(struct Field *field) {
    printf("Enter GPS latitude: ");
    scanf("%f", &field->gpsLatitude);
    printf("Enter GPS longitude: ");
    scanf("%f", &field->gpsLongitude);
    printf("Enter soil health: ");
    scanf("%f", &field->soilHealth);
    printf("Enter moisture level: ");
    scanf("%f", &field->moistureLevel);
    
    printf("Enter number of crops: ");
    scanf("%d", &field->numCrops);
    field->crops = (struct Crop *)malloc(field->numCrops * sizeof(struct Crop));
    for (int i = 0; i < field->numCrops; i++) {
        printf("Enter data for Crop %d:\n", i + 1);
        inputCrop(&field->crops[i]);
    }

    printf("Enter number of equipments: ");
    scanf("%d", &field->numEquipments);
    field->equipments = (struct Equipment *)malloc(field->numEquipments * sizeof(struct Equipment));
    for (int i = 0; i < field->numEquipments; i++) {
        printf("Enter data for Equipment %d:\n", i + 1);
        inputEquipment(&field->equipments[i]);
    }

    printf("Enter number of sensors: ");
    scanf("%d", &field->numSensors);
    field->sensors = (struct Sensor *)malloc(field->numSensors * sizeof(struct Sensor));
    for (int i = 0; i < field->numSensors; i++) {
        printf("Enter data for Sensor %d:\n", i + 1);
        inputSensor(&field->sensors[i]);
    }
}

// Function to input data for a regional hub
void inputRegionalHub(struct RegionalHub *hub) {
    printf("Enter number of fields: ");
    scanf("%d", &hub->numFields);
    hub->fields = (struct Field *)malloc(hub->numFields * sizeof(struct Field));
    
    for (int i = 0; i < hub->numFields; i++) {
        printf("Enter data for Field %d:\n", i + 1);
        inputField(&hub->fields[i]);
    }

    printf("Enter yield prediction: ");
    scanf("%f", &hub->yieldPrediction);
    printf("Enter resource distribution plan: ");
    scanf("%99s", hub->resourceDistribution);
    printf("Enter emergency response plan: ");
    scanf("%99s", hub->emergencyResponsePlan);
}

// Function to display the collected data
void displayData(struct RegionalHub *hub) {
    printf("\n--- Regional Hub Data Summary ---\n");
    for (int i = 0; i < hub->numFields; i++) {
        printf("Field %d:\n", i + 1);
        printf("  GPS Coordinates: Latitude = %.2f, Longitude = %.2f\n",
               hub->fields[i].gpsLatitude, hub->fields[i].gpsLongitude);
        printf("  Soil Health: %.2f, Moisture Level: %.2f\n",
               hub->fields[i].soilHealth, hub->fields[i].moistureLevel);

        for (int j = 0; j < hub->fields[i].numCrops; j++) {
            printf("    Crop %d:\n", j + 1);
            printf("      Type: %s\n", hub->fields[i].crops[j].cropType);
            printf("      Growth Stage: %d\n", hub->fields[i].crops[j].growthStage);
            printf("      Expected Yield: %.2f\n", hub->fields[i].crops[j].expectedYield);
            printf("      Weather: Temperature: %.2f, Rainfall: %.2f, Wind: %.2f\n",
                   hub->fields[i].crops[j].weather.temperature,
                   hub->fields[i].crops[j].weather.rainfall,
                   hub->fields[i].crops[j].weather.windPatterns);
        }

        for (int j = 0; j < hub->fields[i].numEquipments; j++) {
            printf("    Equipment %d:\n", j + 1);
            printf("      Name: %s, Operational: %d, Fuel Level: %.2f, Schedule: %s\n",
                   hub->fields[i].equipments[j].equipmentName,
                   hub->fields[i].equipments[j].operationalStatus,
                   hub->fields[i].equipments[j].fuelLevel,
                   hub->fields[i].equipments[j].activitySchedule);
        }

        for (int j = 0; j < hub->fields[i].numSensors; j++) {
            printf("    Sensor %d:\n", j + 1);
            printf("      Nutrient Data: %s, pH Level: %.2f, Pest Activity: %s\n",
                   hub->fields[i].sensors[j].nutrientData,
                   hub->fields[i].sensors[j].pHLevel,
                   hub->fields[i].sensors[j].pestActivity);
        }
    }

    printf("Yield Prediction: %.2f\n", hub->yieldPrediction);
    printf("Resource Distribution Plan: %s\n", hub->resourceDistribution);
    printf("Emergency Response Plan: %s\n", hub->emergencyResponsePlan);
}

int main() {
    int numHubs;
    printf("Enter the number of regional hubs: ");
    scanf("%d", &numHubs);

    struct RegionalHub *regionalHubs = (struct RegionalHub *)malloc(numHubs * sizeof(struct RegionalHub));

    for (int i = 0; i < numHubs; i++) {
        printf("\nEnter data for Regional Hub %d:\n", i + 1);
        inputRegionalHub(&regionalHubs[i]);
    }

    for (int i = 0; i < numHubs; i++) {
        displayData(&regionalHubs[i]);
    }

    // Free memory
    for (int i = 0; i < numHubs; i++) {
        for (int j = 0; j < regionalHubs[i].numFields; j++) {
            free(regionalHubs[i].fields[j].crops);
            free(regionalHubs[i].fields[j].equipments);
            free(regionalHubs[i].fields[j].sensors);
        }
        free(regionalHubs[i].fields);
    }
    free(regionalHubs);

    return 0;
}
