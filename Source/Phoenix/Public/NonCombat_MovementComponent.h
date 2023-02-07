#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_MovementComponent.h"
#include "NavAgent.h"
#include "NonCombat_MovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNonCombat_MovementComponent : public UAmbulatory_MovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavAgent NavAgent;
    
    UNonCombat_MovementComponent();
};

