#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EMaterialSwapPriority.h"
#include "MaterialParametersInterface.h"
#include "MaterialSwapComponentHandle.h"
#include "MaterialSwapInfo.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialSwapComponent.generated.h"

class AActor;
class UMaterialSwap;
class UMaterialSwapComponent;
class UMeshComponent;
class UTexture;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapComponent : public UActorComponent, public IMaterialParametersInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMeshComponent> SpecificMeshComponent;
    
public:
    UMaterialSwapComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ValidSwap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Swapped() const;
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Name, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    void SetVector4Parameter(FName Name, FVector4 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName Name, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetParameters(const FMaterialSwapParameters& Params);
    
    UFUNCTION(BlueprintCallable)
    void SetColorParameter(FName Name, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    bool RestartSwap();
    
    UFUNCTION(BlueprintCallable)
    bool NewSwapAdvanced(const FMaterialSwapInfo& SwapInfo);
    
    UFUNCTION(BlueprintCallable)
    bool NewSwap(EMaterialSwapPriority Priority, FName Group, FName SubType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void HasMaterialSwap(AActor* Actor, bool& bHasMaterialSwap);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetMaterialSwap(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FMaterialSwapComponentHandle GetCurrentHandle() const;
    
    UFUNCTION(BlueprintCallable)
    void EndSwap(bool AllowRestart, bool ReleaseSwap);
    
    UFUNCTION(BlueprintCallable)
    static bool DestroySwapComponent(UMaterialSwapComponent* MaterialSwapComponent, bool bUnswap);
    
    UFUNCTION(BlueprintCallable)
    static bool DestroySwap(AActor* Actor, bool unswap);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateSwapAdvanced(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo, bool bAlwaysCreateNewComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateSwap(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent, EMaterialSwapPriority Priority, FName Group, FName SubType);
    
    UFUNCTION(BlueprintCallable)
    static bool CreateMeshSwap(UMeshComponent* MeshComponent, UMaterialSwapComponent*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo, bool bAlwaysCreateNewComponent);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetSimpleParameters(const FMaterialSwapParametersSimple& Parameters) override PURE_VIRTUAL(SetSimpleParameters,);
    
};

