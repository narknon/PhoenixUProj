#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EAnimTypeEnum.h"
#include "DialogueLineData.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDialogueLineData : public FTableRowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreRoll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostRoll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimLen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimTypeEnum Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Meta;
    
public:
    FDialogueLineData();
};

