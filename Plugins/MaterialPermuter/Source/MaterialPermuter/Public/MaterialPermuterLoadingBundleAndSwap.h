#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EMaterialPermuterLoadingBundleAndSwapState.h"
#include "MaterialParametersInterface.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterLoadingBundle.h"
#include "MaterialPermuterLoadingBundleAndSwapStateDynamicDelegateDelegate.h"
#include "MaterialSwapKeyUI.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialPermuterLoadingBundleAndSwap.generated.h"

class UHardSwapBatchComponent;
class UMaterialSwap;
class UMaterialSwapComponent;
class UTexture;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialPermuterLoadingBundleAndSwap : public UMaterialPermuterLoadingBundle, public IMaterialParametersInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingBundleAndSwapStateDynamicDelegate OnActorSwapDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapKeyUI MaterialSwapInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingBundleAndSwapState MaterialSwapState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialSwap*> RawMaterialSwaps;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialSwapComponent>> MaterialSwapComponents;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UHardSwapBatchComponent>> HardSwapBatchComponents;
    
    UMaterialPermuterLoadingBundleAndSwap();
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName Name, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetColorParameter(FName Name, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseRawMaterialSwaps(bool bUnswap);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void HasRawMaterialSwaps(int32& RawMaterialsSwapCount) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMaterialSwapState(EMaterialPermuterLoadingBundleAndSwapState& CurrentSwapState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMaterialSwapKey(FMaterialPermuterKey& Key) const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Name, FVector Value) override PURE_VIRTUAL(SetVectorParameter,);
    
    UFUNCTION(BlueprintCallable)
    void SetVector4Parameter(FName Name, FVector4 Value) override PURE_VIRTUAL(SetVector4Parameter,);
    
    UFUNCTION(BlueprintCallable)
    void SetSimpleParameters(const FMaterialSwapParametersSimple& Parameters) override PURE_VIRTUAL(SetSimpleParameters,);
    
};

