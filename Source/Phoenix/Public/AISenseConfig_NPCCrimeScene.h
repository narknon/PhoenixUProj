#pragma once
#include "CoreMinimal.h"
#include "AISenseConfig_NPC.h"
#include "Templates/SubclassOf.h"
#include "AISenseConfig_NPCCrimeScene.generated.h"

class UAISense_NPCCrimeScene;
class UNPC_CrimeSceneSenseAsset;

UCLASS(Blueprintable, EditInlineNew)
class UAISenseConfig_NPCCrimeScene : public UAISenseConfig_NPC {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense_NPCCrimeScene> Implementation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNPC_CrimeSceneSenseAsset* SenseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceiveRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoseRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvaluateInterval;
    
    UAISenseConfig_NPCCrimeScene();
};

