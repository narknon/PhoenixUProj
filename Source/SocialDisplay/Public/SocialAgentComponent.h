#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocialAgentComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SOCIALDISPLAY_API USocialAgentComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_participatesInCollisionAvoidance;
    
public:
    USocialAgentComponent();
};

