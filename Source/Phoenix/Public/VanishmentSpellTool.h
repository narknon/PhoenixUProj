#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TransfigurationSpellToolBase.h"
#include "VanishmentSpellTool.generated.h"

class AVanishmentStyleBase;

UCLASS(Blueprintable)
class AVanishmentSpellTool : public ATransfigurationSpellToolBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AVanishmentStyleBase>> VanishmentStyles;
    
public:
    AVanishmentSpellTool(const FObjectInitializer& ObjectInitializer);
};

