#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "DbSingleColumnInfo.h"
#include "SceneRigParticipant.h"
#include "Actor_NamedCreature.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_NamedCreature : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo DBInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExistingDOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DOVName;
    
    UActor_NamedCreature();
    
    // Fix for true pure virtual functions not being implemented
};

