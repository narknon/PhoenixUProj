#pragma once
#include "CoreMinimal.h"
#include "ToolRecord.h"
#include "Templates/SubclassOf.h"
#include "ItemToolRecord.generated.h"

class AItemTool;

UCLASS(Blueprintable)
class UItemToolRecord : public UToolRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItemTool> ItemTool;
    
    UItemToolRecord();
};

