#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "Templates/SubclassOf.h"
#include "SceneAction_ExecuteAblAbility.generated.h"

class UAblAbility;
class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ExecuteAblAbility : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> AblAbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PartialBodyAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* OtherActor;
    
    USceneAction_ExecuteAblAbility();
};

