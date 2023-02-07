#pragma once
#include "CoreMinimal.h"
#include "AncientMagicEffect.h"
#include "Templates/SubclassOf.h"
#include "AncientMagicEffect_Nova.generated.h"

class AActor;
class AAncientMagicNova;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAncientMagicEffect_Nova : public UAncientMagicEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> NovaClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NovaExpandSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NovaExpandDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HidePlayerWhileActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAncientMagicNova* NovaActor;
    
    UAncientMagicEffect_Nova();
    UFUNCTION(BlueprintCallable)
    void NovaFinished(const UObject* Object);
    
};

