#include "MaterialSwapComponentAutoRefresh.h"

class AActor;
class UMaterialSwapComponentAutoRefresh;

void UMaterialSwapComponentAutoRefresh::HasAutoRefreshMaterialSwap(AActor* Actor, bool& bHasMaterialSwap) {
}

void UMaterialSwapComponentAutoRefresh::GetAutoRefreshMaterialSwap(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapAutoRefreshComponent) {
}

bool UMaterialSwapComponentAutoRefresh::CreateSwapAutoRefresh(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapComponent, EMaterialSwapPriority Priority, FName Group, FName SubType) {
    return false;
}

bool UMaterialSwapComponentAutoRefresh::CreateSwapAdvancedAutoRefresh(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo) {
    return false;
}

UMaterialSwapComponentAutoRefresh::UMaterialSwapComponentAutoRefresh() {
    this->SavedSwapInfo = NULL;
}

