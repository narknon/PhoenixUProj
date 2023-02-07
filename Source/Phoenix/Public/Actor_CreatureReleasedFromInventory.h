#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "DbSingleColumnInfo.h"
#include "SceneRigParticipant.h"
#include "Actor_CreatureReleasedFromInventory.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_CreatureReleasedFromInventory : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGetSavedCreature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SavedCreatureID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo DBInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExistingDOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ExistingDOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NurturingSpaceOverride;
    
    UActor_CreatureReleasedFromInventory();
    
    // Fix for true pure virtual functions not being implemented
};

