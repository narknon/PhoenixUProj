#include "TrainManager.h"

class UTrainManager;

void UTrainManager::SetupTrain() {
}

void UTrainManager::SetTrainSpeed(float Speed) {
}

void UTrainManager::SetTrainPositionAlongTrack(FVector Position) {
}

void UTrainManager::SetTrainDistanceAlongTrack(float Distance) {
}

UTrainManager* UTrainManager::Get() {
    return NULL;
}

void UTrainManager::CleanupTrain() {
}

UTrainManager::UTrainManager() {
    this->TrainEngine = NULL;
    this->CoalCar = NULL;
    this->NavigationSpline = NULL;
}

