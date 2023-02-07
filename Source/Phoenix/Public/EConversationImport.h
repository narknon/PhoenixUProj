#pragma once
#include "CoreMinimal.h"
#include "EConversationImport.generated.h"

UENUM(BlueprintType)
enum class EConversationImport : uint8 {
    ImportFromArticy,
    DoNotImportFromArticy,
};

