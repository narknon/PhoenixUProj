#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_Creature_ActorContainsGroupCoordinatedTag.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_Creature_ActorContainsGroupCoordinatedTag : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UEnvQueryTest_Creature_ActorContainsGroupCoordinatedTag();
};

