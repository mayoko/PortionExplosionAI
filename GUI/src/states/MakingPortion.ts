export enum PortionType {
    PORTION_OF_WISDOM = 'Portion of Wisdom',
    PORTION_OF_MAGNETICAL_ATTRACTION = 'Portion of Magnetical Attraction',
    ABYSSAL_DRAFT = 'Abyssal Draft',
    BALM_OF_UTTERMOST_STICKNESS = 'Balm of Uttermost Stickiness',
    ELIXIR_OF_BLIND_LOVE = 'Elixir of Blind Love',
    PORTION_OF_PRISMATIC_JOY = 'Portion of Prismatic Joy',
    SANDS_OF_TIME = 'Sands of Time',
    FILTER_OF_LAVAMANCING = 'Filter of Lavamancing',
    NONE = 'NONE',
}

export enum MarbleColor {
    RED = 'RED',
    BLUE = 'BLUE',
    YELLOW = 'YELLOW',
    BLACK = 'BLACK',
    NONE = 'NONE',
}

export const stringToMarbleColor = (colorString: string): MarbleColor => {
    const matchedMarbleColor = Object.values(MarbleColor).filter(
        value => value === colorString,
    );

    return matchedMarbleColor.length > 0
        ? matchedMarbleColor[0]
        : MarbleColor.NONE;
};

export default interface MakingPortion {
    type: PortionType;
    restColors: { color: MarbleColor; count: number }[];
}
