#include "VirtualContainer.h"

bool UVirtualContainer::IsFinite(const FString& ContainerID) {
    return false;
}

TArray<FVCSlot> UVirtualContainer::GetContents(const FString& ContainerID) {
    return TArray<FVCSlot>();
}

UVirtualContainer::UVirtualContainer() {
}

