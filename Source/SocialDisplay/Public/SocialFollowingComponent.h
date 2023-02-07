#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PreferredNavDataPathFollowingComponent.h"
#include "SocialFollowingComponent.generated.h"

class USocialAgentPawnComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SOCIALDISPLAY_API USocialFollowingComponent : public UPreferredNavDataPathFollowingComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USocialAgentPawnComponent* m_agent;
    
public:
    USocialFollowingComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void OnMovementUpdated(float i_deltaSeconds, FVector i_oldLocation, FVector i_oldVelocity);
    
};

