#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EDoorState.h"
#include "LockableManagerFunctionLibrary.generated.h"

class ADoor;

UCLASS(Blueprintable)
class ULockableManagerFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULockableManagerFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void WaitForDoorAndSetState(const FString& DoorName, EDoorState DoorState, bool LockVisible, bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable)
    static ADoor* FindNamedDoor(const FString& DoorName);
    
};

