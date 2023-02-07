#pragma once
#include "CoreMinimal.h"
#include "UtilityContext.h"
#include "ActionEnergyData.h"
#include "CreatureUtilityContext.generated.h"

class AActor;
class ACreature_Character;
class UCreatureDefinition;
class UCreatureState;
class UObjectStateInfo;

UCLASS(Blueprintable)
class PHOENIX_API UCreatureUtilityContext : public UUtilityContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* SelfCreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObjectStateInfo* SelfObjectStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCreatureDefinition* SelfCreatureDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCreatureState* SelfCreatureState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> TransfigurationActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FActionEnergyData> ActionEnergyData;
    
    UCreatureUtilityContext();
};

