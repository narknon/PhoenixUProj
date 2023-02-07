#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GlobalLightingCustomBlendableNameLinearColor.h"
#include "GlobalLightingCustomBlendableNameScalar.h"
#include "GlobalLightingCustomBlendablesLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGlobalLightingCustomBlendablesLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetGlobalLightingCustomBlendableScalarName(UObject* WorldContextObject, FName ScalarName, float& ScalarValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetGlobalLightingCustomBlendableScalar(UObject* WorldContextObject, FGlobalLightingCustomBlendableNameScalar Scalar, float& ScalarValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetGlobalLightingCustomBlendableLinearColorName(UObject* WorldContextObject, FName ColorName, FLinearColor& ColorValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetGlobalLightingCustomBlendableLinearColor(UObject* WorldContextObject, FGlobalLightingCustomBlendableNameLinearColor Color, FLinearColor& ColorValue);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDefaultGlobalLightingCustomBlendableScalarName(FName ScalarName, float& ScalarValue);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDefaultGlobalLightingCustomBlendableScalar(FGlobalLightingCustomBlendableNameScalar Scalar, float& ScalarValue);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDefaultGlobalLightingCustomBlendableLinearColorName(FName ColorName, FLinearColor& ColorValue);
    
    UFUNCTION(BlueprintCallable)
    static bool GetDefaultGlobalLightingCustomBlendableLinearColor(FGlobalLightingCustomBlendableNameLinearColor Color, FLinearColor& ColorValue);
    
};

