#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LightComponentStates.h"
#include "LightComponentStatesSaveData.h"
#include "LightComponentStatesLibrary.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class ULightComponentStatesLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULightComponentStatesLibrary();
    UFUNCTION(BlueprintCallable)
    static void LightComponentStatesUpdate(AActor* Actor, UPARAM(Ref) FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bIncludeChildActors);
    
    UFUNCTION(BlueprintCallable)
    static void LightComponentStatesRestore(UPARAM(Ref) FLightComponentStatesSaveData& LightComponentStatesSaveData);
    
    UFUNCTION(BlueprintCallable)
    static void LightComponentStatesInitialize(UObject* Owner, UPARAM(Ref) FLightComponentStatesSaveData& LightComponentStatesSaveData, FLightComponentStates LightComponentStates);
    
    UFUNCTION(BlueprintCallable)
    static void AddLightComponentStateVisibility(UObject* Owner, UPARAM(Ref) FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    static void AddLightComponentStateCastShadow(UObject* Owner, UPARAM(Ref) FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bCastShadow);
    
};

