#include "WaitForNamedDoorToLoadNode.h"

class UObject;
class UWaitForNamedDoorToLoadNode;

UWaitForNamedDoorToLoadNode* UWaitForNamedDoorToLoadNode::WaitForNamedDoorToLoad(const UObject* WorldContextObject, const FString& DoorName, float TimeOutSeconds) {
    return NULL;
}

void UWaitForNamedDoorToLoadNode::FindDoorOrQueue() {
}

UWaitForNamedDoorToLoadNode::UWaitForNamedDoorToLoadNode() {
    this->World = NULL;
}

