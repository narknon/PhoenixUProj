#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_MovementComponent.h"
#include "NPC_MovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_MovementComponent : public UAmbulatory_MovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseConfinedRotationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeRootCapsuleInMultiCapsuleSweeps;
    
    UNPC_MovementComponent();
};

