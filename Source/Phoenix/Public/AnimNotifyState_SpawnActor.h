#pragma once
#include "CoreMinimal.h"
#include "AnimNotifyState_SpawnActorBase.h"
#include "Templates/SubclassOf.h"
#include "AnimNotifyState_SpawnActor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_SpawnActor : public UAnimNotifyState_SpawnActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SpawnActorClass;
    
    UAnimNotifyState_SpawnActor();
};

