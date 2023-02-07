#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MaterialSwapParametersSimple.h"
#include "MaterialParametersInterface.generated.h"

class UTexture;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UMaterialParametersInterface : public UInterface {
    GENERATED_BODY()
};

class IMaterialParametersInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void SetVectorParameter(FName Name, FVector Value) PURE_VIRTUAL(SetVectorParameter,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetVector4Parameter(FName Name, FVector4 Value) PURE_VIRTUAL(SetVector4Parameter,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetTextureParameter(FName Name, UTexture* Value) PURE_VIRTUAL(SetTextureParameter,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetSimpleParameters(const FMaterialSwapParametersSimple& Parameters) PURE_VIRTUAL(SetSimpleParameters,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetScalarParameter(FName Name, float Value) PURE_VIRTUAL(SetScalarParameter,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetColorParameter(FName Name, FLinearColor Value) PURE_VIRTUAL(SetColorParameter,);
    
};

