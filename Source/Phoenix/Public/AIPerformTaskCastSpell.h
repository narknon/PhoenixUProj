#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EPerformTasksSpell.h"
#include "Templates/SubclassOf.h"
#include "AIPerformTaskCastSpell.generated.h"

class AActor;
class UAblAbility;
class USpellToolRecord;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskCastSpell : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* SpellTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTasksSpell SpellType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CustomSpellAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* CustomSpellToolRecord;
    
public:
    UAIPerformTaskCastSpell();
protected:
    UFUNCTION(BlueprintCallable)
    void WeaponsAreReady(AActor* InActor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTargetActorSpawnInFinished(AActor* SpawnedActor);
    
};

