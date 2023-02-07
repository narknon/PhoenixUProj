#pragma once
#include "CoreMinimal.h"
#include "ablExecuteTaskSubScratchPad.h"
#include "abl_SpiderAttack_SubScratchPad.generated.h"

class UEnemy_SpawnSpiders;

UCLASS(Blueprintable, Transient)
class Uabl_SpiderAttack_SubScratchPad : public UablExecuteTaskSubScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_SpawnSpiders* SpawnSpidersPtr;
    
    Uabl_SpiderAttack_SubScratchPad();
};

