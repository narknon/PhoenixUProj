#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "WidgetType.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FWidgetType : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> Widget;
    
    PHOENIX_API FWidgetType();
};

