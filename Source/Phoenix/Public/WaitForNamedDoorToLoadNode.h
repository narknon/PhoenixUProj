#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FoundDoorDelegateDelegate.h"
#include "TimedOutDelegateDelegate.h"
#include "WaitForNamedDoorToLoadNode.generated.h"

class UObject;
class UWaitForNamedDoorToLoadNode;
class UWorld;

UCLASS(Blueprintable)
class UWaitForNamedDoorToLoadNode : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFoundDoorDelegate FoundDoor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimedOutDelegate TimedOut;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
public:
    UWaitForNamedDoorToLoadNode();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UWaitForNamedDoorToLoadNode* WaitForNamedDoorToLoad(const UObject* WorldContextObject, const FString& DoorName, float TimeOutSeconds);
    
private:
    UFUNCTION(BlueprintCallable)
    void FindDoorOrQueue();
    
};

