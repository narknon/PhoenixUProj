#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "RaiseCurtainActionOutputPinDelegate.h"
#include "RaiseCurtainAction.generated.h"

class UCurtainSubsystem;
class UObject;
class URaiseCurtainAction;

UCLASS(Blueprintable)
class URaiseCurtainAction : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRaiseCurtainActionOutputPin CurtainRaised;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurtainSubsystem* CurtainSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WhosAsking;
    
public:
    URaiseCurtainAction();
    UFUNCTION(BlueprintCallable)
    static URaiseCurtainAction* RaiseCurtain(UObject* NewWhosAsking);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
};

