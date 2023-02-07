#pragma once
#include "CoreMinimal.h"
#include "MapScreenBase.h"
#include "DungeonMapScreen.generated.h"

class UMapDungeon;

UCLASS(Blueprintable, EditInlineNew)
class UDungeonMapScreen : public UMapScreenBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapDungeon* DungeonMap;
    
    UDungeonMapScreen();
};

