#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpringFollowActor.generated.h"

class USpringFollowComponent;

UCLASS(Blueprintable)
class ASpringFollowActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpringsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadialDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringFollowComponent* SpringFollow;
    
    ASpringFollowActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ResetPhysics();
    
};

