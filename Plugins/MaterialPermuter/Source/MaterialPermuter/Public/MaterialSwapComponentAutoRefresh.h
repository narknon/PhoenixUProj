#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapPriority.h"
#include "MaterialSwapComponent.h"
#include "MaterialSwapInfo.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapComponentAutoRefresh.generated.h"

class AActor;
class UMaterialSwapComponentAutoRefresh;
class UMaterialSwapInfoObjectBase;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapComponentAutoRefresh : public UMaterialSwapComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwapInfoObjectBase* SavedSwapInfo;
    
public:
    UMaterialSwapComponentAutoRefresh();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void HasAutoRefreshMaterialSwap(AActor* Actor, bool& bHasMaterialSwap);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAutoRefreshMaterialSwap(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapAutoRefreshComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateSwapAutoRefresh(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapComponent, EMaterialSwapPriority Priority, FName Group, FName SubType);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateSwapAdvancedAutoRefresh(AActor* Actor, UMaterialSwapComponentAutoRefresh*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo);
    
};

