#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RenderingCutBits.h"
#include "RenderingCutsBluprintLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class URenderingCutsBluprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URenderingCutsBluprintLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TriggerRenderingCut(UObject* WorldContextObject, FRenderingCutBits RenderingCuts);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TriggerCameraCut(UObject* WorldContextObject);
    
};

