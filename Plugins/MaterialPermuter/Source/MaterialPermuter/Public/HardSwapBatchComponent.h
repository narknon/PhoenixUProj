#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ActorToHardSwapList.h"
#include "EHardSwapBatchComponentState.h"
#include "HardSwapBatchComponentActorSwappedDynamicDelegateDelegate.h"
#include "HardSwapBatchComponentDoneDynamicDelegateDelegate.h"
#include "HardSwapBatchComponentSettings.h"
#include "MaterialParametersInterface.h"
#include "MaterialPermuterHardSwapBase.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialSwapSharedMIDCache.h"
#include "HardSwapBatchComponent.generated.h"

class AActor;
class UMaterialPermuterLibrary;
class UTexture;

UCLASS(Abstract, Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UHardSwapBatchComponent : public UActorComponent, public IMaterialParametersInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentDoneDynamicDelegate OnDoneDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentActorSwappedDynamicDelegate OnActorSwappedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLibrary* Library;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterHardSwapBase HardSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardSwapBatchComponentSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapSharedMIDCache MIDCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHardSwapBatchComponentState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorToHardSwapList ActorsToSwap;
    
    UHardSwapBatchComponent();
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName Name, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetColorParameter(FName Name, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetActorsToSwap(TArray<AActor*>& ActorsToSwapList);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Name, FVector Value) override PURE_VIRTUAL(SetVectorParameter,);
    
    UFUNCTION(BlueprintCallable)
    void SetVector4Parameter(FName Name, FVector4 Value) override PURE_VIRTUAL(SetVector4Parameter,);
    
    UFUNCTION(BlueprintCallable)
    void SetSimpleParameters(const FMaterialSwapParametersSimple& Parameters) override PURE_VIRTUAL(SetSimpleParameters,);
    
};

