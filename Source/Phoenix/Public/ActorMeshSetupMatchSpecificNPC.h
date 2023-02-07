#pragma once
#include "CoreMinimal.h"
#include "ActorMeshSetupMatch.h"
#include "DbSingleColumnInfo.h"
#include "ActorMeshSetupMatchSpecificNPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActorMeshSetupMatchSpecificNPC : public UActorMeshSetupMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NPCKey;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NPCKeyName;
    
public:
    UActorMeshSetupMatchSpecificNPC();
};

