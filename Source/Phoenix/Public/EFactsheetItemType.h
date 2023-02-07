#pragma once
#include "CoreMinimal.h"
#include "EFactsheetItemType.generated.h"

UENUM(BlueprintType)
enum EFactsheetItemType {
    FACTSHEET_ITEM_TYPE_UNKNOWN,
    FACTSHEET_ITEM_TYPE_PERSON,
    FACTSHEET_ITEM_TYPE_MAX UMETA(Hidden),
};

