#pragma once
#include "CoreMinimal.h"
#include "AncientMagicEffect.h"
#include "Templates/SubclassOf.h"
#include "AncientMagicEffect_Test.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAncientMagicEffect_Test : public UAncientMagicEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> NovaClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NovaExpandSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NovaExpandDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* NovaActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> NotifyList;
    
    UAncientMagicEffect_Test();
    UFUNCTION(BlueprintCallable)
    void CollisionDetected(AActor* Actor);
    
};

