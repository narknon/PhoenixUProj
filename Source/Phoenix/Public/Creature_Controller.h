#pragma once
#include "CoreMinimal.h"
#include "UtilityContextProvider.h"
#include "NPC_Controller.h"
#include "Creature_Controller.generated.h"

class UCreatureUtilityContext;
class UCreature_PathFollowingComponent;

UCLASS(Blueprintable)
class PHOENIX_API ACreature_Controller : public ANPC_Controller, public IUtilityContextProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavmeshQueryHorizontalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavmeshQueryVerticalUpRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavmeshQueryVerticalDownRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavmeshQueryOffMeshMaxRadius;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_PathFollowingComponent* CreaturePathFollowingComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCreatureUtilityContext* CreatureUtilityContext;
    
public:
    ACreature_Controller();
    
    // Fix for true pure virtual functions not being implemented
};

