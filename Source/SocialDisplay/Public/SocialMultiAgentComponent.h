#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocialMultiAgentMember.h"
#include "SocialMultiAgentComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SOCIALDISPLAY_API USocialMultiAgentComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSocialMultiAgentMember> MemberAgents;
    
public:
    USocialMultiAgentComponent();
};

