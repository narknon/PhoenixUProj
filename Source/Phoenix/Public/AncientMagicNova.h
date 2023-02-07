#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AncientMagicNova.generated.h"

class UObject;

UCLASS(Blueprintable)
class AAncientMagicNova : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpandSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxExpandSize;
    
    AAncientMagicNova();
    UFUNCTION(BlueprintCallable)
    void SetNotifyObject(UObject* Object);
    
};

