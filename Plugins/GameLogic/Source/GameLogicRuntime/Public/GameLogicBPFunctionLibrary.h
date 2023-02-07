#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameLogicBPFunctionLibrary.generated.h"

class UGameLogicObject;
class UObject;

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicBPFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UGameLogicBPFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static UGameLogicObject* SpawnAndAttachToGameLogicObject(UObject* InBlueprint);
    
    UFUNCTION(BlueprintCallable)
    static void DetachFromGameLogicEvents(UObject* InputReceiver, UGameLogicObject* GameLogicObject);
    
    UFUNCTION(BlueprintCallable)
    static void AttachToGameLogicEvents(UObject* InputReceiver, UGameLogicObject* GameLogicObject);
    
};

