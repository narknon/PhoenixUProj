#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialDefaultParameters.h"
#include "MaterialDefaultParametersBlueprintLibrary.generated.h"

class UMaterialInterface;
class UTexture;

UCLASS(Blueprintable)
class UMaterialDefaultParametersBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMaterialDefaultParametersBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetMaterialDefaultVectorParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, FLinearColor& DefaultValue, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetMaterialDefaultTextureParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, UTexture*& DefaultValue, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetMaterialDefaultScalarParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, float& DefaultValue, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void GetMaterialDefaultParameters(UMaterialInterface* Material, FMaterialDefaultParameters& MaterialDefaultParameters);
    
};

