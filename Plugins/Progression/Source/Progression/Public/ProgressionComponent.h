#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProgressionComponent.generated.h"

class UPT_Progression;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PROGRESSION_API UProgressionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPT_Progression* m_progression;
    
    UProgressionComponent();
};

