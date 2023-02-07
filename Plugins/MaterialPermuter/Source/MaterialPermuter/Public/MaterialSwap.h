#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EMaterialSwapPriority.h"
#include "MaterialParametersInterface.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterUnswapInterface.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialSwap.generated.h"

class UTexture;

UCLASS(Abstract, Blueprintable, Transient)
class MATERIALPERMUTER_API UMaterialSwap : public UObject, public IMaterialPermuterUnswapInterface, public IMaterialParametersInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EMaterialSwapPriority Priority;
    
public:
    UMaterialSwap();
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Name, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    void SetVector4Parameter(FName Name, FVector4 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName Name, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetColorParameter(FName Name, FLinearColor Value);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetSimpleParameters(const FMaterialSwapParametersSimple& Parameters) override PURE_VIRTUAL(SetSimpleParameters,);
    
};

