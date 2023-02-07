#pragma once
#include "CoreMinimal.h"
#include "ChannelingSpellTool.h"
#include "Templates/SubclassOf.h"
#include "GenericBPSpellTool.generated.h"

class AActor;

UCLASS(Blueprintable)
class AGenericBPSpellTool : public AChannelingSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> BPActorClass;
    
    AGenericBPSpellTool();
};

