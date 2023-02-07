#pragma once
#include "CoreMinimal.h"
#include "MenuReaderVoice.generated.h"

USTRUCT(BlueprintType)
struct FMenuReaderVoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString VoiceID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Gender;
    
    PHOENIX_API FMenuReaderVoice();
};

