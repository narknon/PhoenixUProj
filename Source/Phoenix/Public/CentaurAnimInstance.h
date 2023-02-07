#pragma once
#include "CoreMinimal.h"
#include "NPC_AnimInstance.h"
#include "CentaurAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UCentaurAnimInstance : public UNPC_AnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeftHandBowHold;
    
    UCentaurAnimInstance();
};

