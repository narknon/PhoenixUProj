#pragma once
#include "CoreMinimal.h"
#include "MailEntry.generated.h"

USTRUCT(BlueprintType)
struct FMailEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_sender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_mailKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bShouldAutoPlay;
    
    PHOENIX_API FMailEntry();
};

