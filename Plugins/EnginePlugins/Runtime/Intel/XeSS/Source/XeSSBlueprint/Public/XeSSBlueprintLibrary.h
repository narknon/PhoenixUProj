#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EXeSSQualityMode.h"
#include "XeSSBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class UXeSSBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UXeSSBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetXeSSQualityMode(EXeSSQualityMode QualityMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsXeSSSupported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EXeSSQualityMode GetXeSSQualityMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<EXeSSQualityMode> GetSupportedXeSSQualityModes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EXeSSQualityMode GetDefaultXeSSQualityMode(FIntPoint ScreenResolution);
    
};

